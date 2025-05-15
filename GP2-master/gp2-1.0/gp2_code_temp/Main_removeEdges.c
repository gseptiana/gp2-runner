#include "Main_removeEdges.h"

static bool match_n0(Morphism *morphism);
static bool match_e0(Morphism *morphism);
static bool match_n1(Morphism *morphism, Edge *host_edge);

bool matchMain_removeEdges(Morphism *morphism)
{
   if(host->number_of_nodes < 2 || host->number_of_edges < 1) return false;
   if(match_n0(morphism)) return true;
   else
   {
      clearMatched(morphism);
      initialiseMorphism(morphism);
      return false;
   }
}

static bool match_n0(Morphism *morphism)
{
   NodeList *nlistpos;
   nlistpos = NULL;
   for(Node *host_node; (host_node = yieldNextNode(host, &nlistpos, 0)) != NULL;)
   {
      if(nodeMatched(host_node)) continue;
      if(host_node->label.mark != 0) continue;
      if(nodeOutDegree(host_node) < 1       ||
         ((nodeOutDegree(host_node) + nodeInDegree(host_node)) < 1)) continue;

      HostLabel label = host_node->label;
      bool match = false;
      /* Label Matching */
      int new_assignments = 0;
      do
      {
         /* The rule list does not contain a list variable, so there is no
          * match if the host list has a different length. */
         if(label.length != 1) break;
         HostListItem *item = label.list->first;
         /* Matching rule atom 1. */
         int result = -1;
         /* Matching string variable 0. */
         if(item->atom.type != 's') break;
         result = addStringAssignment(morphism, 0, item->atom.str);
         if(result >= 0)
         {
            new_assignments += result;
         }
         else break;
         match = true;
      } while(false);

      if(match)
      {
         addNodeMap(morphism, 0, host_node, new_assignments);
         setNodeMatched(host_node);
         if(match_e0(morphism)) return true;
         else
         {
            removeNodeMap(morphism, 0);
            clearNodeMatched(host_node);
         }
      }
      else removeAssignments(morphism, new_assignments);
   }
   return false;
}

static bool match_e0(Morphism *morphism)
{
   /* Start node is the already-matched node from which the candidate
      edges are drawn. End node may or may not have been matched already. */
   Node *host_node = lookupNode(morphism, 0);
   Node *end_node = lookupNode(morphism, 1);
   if(host_node == NULL) return false;
   EdgeList *elistpos;
   elistpos = NULL;
   for(Edge *host_edge; (host_edge = yieldNextOutEdge(host, host_node, &elistpos, 0, false)) != NULL;)
   {
      if(edgeMatched(host_edge)) continue;
      if(edgeSource(host_edge) == edgeTarget(host_edge)) continue;
      if(host_edge->label.mark != 0) continue;

      /* If the end node has been matched, check that the edgeTarget of the
       * host edge is the image of the end node. */
      if(end_node != NULL)
      {
         if(edgeTarget(host_edge) != end_node) continue;
      }
      /* Otherwise, the edgeTarget of the host edge should be unmatched. */
      else if(nodeMatched(edgeTarget(host_edge))) continue;
      HostLabel label = host_edge->label;
      bool match = false;
      /* Label Matching */
      int new_assignments = 0;
      do
      {
         /* The rule list does not contain a list variable, so there is no
          * match if the host list has a different length. */
         if(label.length != 1) break;
         HostListItem *item = label.list->first;
         /* Matching rule atom 1. */
         int result = -1;
         /* Matching integer variable 2. */
         if(item->atom.type != 'i') break;
         result = addIntegerAssignment(morphism, 2, item->atom.num);
         if(result >= 0)
         {
            new_assignments += result;
         }
         else break;
         match = true;
      } while(false);

      if(match)
      {
         addEdgeMap(morphism, 0, host_edge, new_assignments);
         setEdgeMatched(host_edge);
         if(match_n1(morphism, host_edge)) return true;
         else
         {
            removeEdgeMap(morphism, 0);
            clearEdgeMatched(host_edge);
         }
      }
      else removeAssignments(morphism, new_assignments);
   }

   return false;
}

static bool match_n1(Morphism *morphism, Edge *host_edge)
{
   Node *host_node = edgeTarget(host_edge);

   if(nodeMatched(host_node)) return false;
   if(host_node->label.mark != 0) return false;
      if(nodeInDegree(host_node) < 1       ||
         ((nodeOutDegree(host_node) + nodeInDegree(host_node)) < 1)) return false;

   HostLabel label = host_node->label;
   bool match = false;
   /* Label Matching */
   int new_assignments = 0;
   do
   {
      /* The rule list does not contain a list variable, so there is no
       * match if the host list has a different length. */
      if(label.length != 1) break;
      HostListItem *item = label.list->first;
      /* Matching rule atom 1. */
      int result = -1;
      /* Matching string variable 1. */
      if(item->atom.type != 's') break;
      result = addStringAssignment(morphism, 1, item->atom.str);
      if(result >= 0)
      {
         new_assignments += result;
      }
      else break;
      match = true;
   } while(false);

   if(match)
   {
      addNodeMap(morphism, 1, host_node, new_assignments);
      setNodeMatched(host_node);
      /* All items matched! */
      return true;
   }
   else removeAssignments(morphism, new_assignments);
   return false;
}

void applyMain_removeEdges(Morphism *morphism, bool record_changes)
{
   Edge *host_edge = lookupEdge(morphism, 0);
   if(record_changes) pushRemovedEdge(host_edge);
   removeEdge(host, host_edge);

   /* Reset the morphism. */
   clearMatched(morphism);
   initialiseMorphism(morphism);
}

