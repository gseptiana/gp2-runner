#include <time.h>
#include <Judy.h>
#include "common.h"
#include "debug.h"
#include "graph.h"
#include "graphStacks.h"
#include "parser.h"
#include "lexer.c"
#include "morphism.h"

#include "Main_rec.h"
Morphism *M_Main_rec = NULL;
#include "Main_removeEdges.h"
Morphism *M_Main_removeEdges = NULL;

static void freeMorphisms(void)
{
   freeMorphism(M_Main_rec);
   freeMorphism(M_Main_removeEdges);
}

static void garbageCollect(void)
{
   freeMorphisms();
   freeGraphChangeStack();
   freeGraph(host);
   freeHostListStore();
}

Graph *host = NULL;
Pvoid_t node_map = (Pvoid_t) NULL;

static Graph *buildHostGraph(char *host_file)
{
   yyin = fopen(host_file, "r");
   if(yyin == NULL)
   {
      perror(host_file);
      return NULL;
   }

   host = newGraph();
   setStackGraph(host);
   /* The parser populates the host graph using node_map to add edges with
    * the correct source and target indices. */
   int result = yyparse();
   fclose(yyin);
   yylex_destroy();
   yy_delete_buffer(YY_CURRENT_BUFFER);
   Word_t Rc_word;
   JLFA(Rc_word, node_map);
   if(result == 0) return host;
   else
   {
      freeGraph(host);
      return NULL;
   }
}

bool success = true;

int main(int argc, char **argv)
{
   srand(time(NULL));
   openLogFile("gp2.log");

   if(argc != 2)
   {
      fprintf(stderr, "Error: missing <host-file> argument.\n");
      return 0;
   }

   clock_t start_time_gb = clock();
   initialiseHostListStore();
   host = buildHostGraph(argv[1]);
   if(host == NULL)
   {
      fprintf(stderr, "Error parsing host graph file.\n");
      return 0;
   }
   FILE *output_file = fopen("gp2.output", "w");
   if(output_file == NULL)
   {
      perror("gp2.output");
      exit(1);
   }
   clock_t start_time_ngb = clock();
   M_Main_rec = makeMorphism(4, 3, 7);
   M_Main_removeEdges = makeMorphism(2, 1, 3);

   /* Loop Statement */
   while(success)
   {
      /* Rule Call */
      if(matchMain_rec(M_Main_rec))
      {
         applyMain_rec(M_Main_rec, false);
         success = true;
      }
      else
      {
         success = false;
      }
   }
   success = true;
   /* Loop Statement */
   while(success)
   {
      /* Rule Call */
      if(matchMain_removeEdges(M_Main_removeEdges))
      {
         applyMain_removeEdges(M_Main_removeEdges, false);
         success = true;
      }
      else
      {
         success = false;
      }
   }
   success = true;
   double elapsed_time_gb = (double)(clock()-start_time_gb)/CLOCKS_PER_SEC;
   double elapsed_time_ngb = (double)(clock()-start_time_ngb)/CLOCKS_PER_SEC;
   FILE *bench = fopen("timings_gp2.dat", "w");
   fprintf(bench, "Incl. graph building (ms): %f\n", elapsed_time_gb*1000);
   fprintf(bench, "Excl. graph building (ms): %f", elapsed_time_ngb*1000);
   printGraph(host, output_file);
   garbageCollect();
   closeLogFile();
   printf("Output graph saved to file gp2.output\n");
   printf("Execution timings saved to file timings_gp2.dat\n");
   fclose(output_file);
   fclose(bench);
   return 0;
}

