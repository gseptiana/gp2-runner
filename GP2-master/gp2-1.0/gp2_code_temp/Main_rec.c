#include "Main_rec.h"

bool b0 = true;
bool b1 = true;
bool b2 = true;
bool b3 = false;

static bool evaluateCondition(void)
{
   return (((b0 && b1) && b2) && !b3);
}

static void evaluatePredicate0(Morphism *morphism)
{
   Assignment assignment_4 = getAssignment(morphism, 4);
   /* If the variable is not yet assigned, return. */
   if(assignment_4.type == 'n') return;
   int var_4 = getIntegerValue(morphism, 4);

   if(var_4 >= 80) b0 = true;
   else b0 = false;
}

static void evaluatePredicate1(Morphism *morphism)
{
   Assignment assignment_5 = getAssignment(morphism, 5);
   /* If the variable is not yet assigned, return. */
   if(assignment_5.type == 'n') return;
   int var_5 = getIntegerValue(morphism, 5);

   if(var_5 >= 80) b1 = true;
   else b1 = false;
}

static void evaluatePredicate2(Morphism *morphism)
{
   Assignment assignment_6 = getAssignment(morphism, 6);
   /* If the variable is not yet assigned, return. */
   if(assignment_6.type == 'n') return;
   int var_6 = getIntegerValue(morphism, 6);

   if(var_6 >= 80) b2 = true;
   else b2 = false;
}

static void evaluatePredicate3(Morphism *morphism)
{
   Node *n1 = lookupNode(morphism, 1);
   /* If the node is not yet matched by the morphism, return. */
   if(n1 == NULL) return;

   Node *n3 = lookupNode(morphism, 3);
   /* If the node is not yet matched by the morphism, return. */
   if(n3 == NULL) return;

   bool edge_found = false;
   EdgeList *elist;
   elist = NULL;
   for(Edge *edge; (edge = yieldNextOutEdge(host, n1, &elist, 0, 0)) != NULL && !edge_found;)
   {
      if(edge != NULL && edgeTarget(edge) == n3)
      {
         b3 = true;
         edge_found = true;
         break;
      }
   }
   elist = NULL;
   for(Edge *edge; (edge = yieldNextOutEdge(host, n1, &elist, 1, 0)) != NULL && !edge_found;)
   {
      if(edge != NULL && edgeTarget(edge) == n3)
      {
         b3 = true;
         edge_found = true;
         break;
      }
   }
   elist = NULL;
   for(Edge *edge; (edge = yieldNextOutEdge(host, n1, &elist, 2, 0)) != NULL && !edge_found;)
   {
      if(edge != NULL && edgeTarget(edge) == n3)
      {
         b3 = true;
         edge_found = true;
         break;
      }
   }
   elist = NULL;
   for(Edge *edge; (edge = yieldNextOutEdge(host, n1, &elist, 3, 0)) != NULL && !edge_found;)
   {
      if(edge != NULL && edgeTarget(edge) == n3)
      {
         b3 = true;
         edge_found = true;
         break;
      }
   }
   elist = NULL;
   for(Edge *edge; (edge = yieldNextOutEdge(host, n1, &elist, 4, 0)) != NULL && !edge_found;)
   {
      if(edge != NULL && edgeTarget(edge) == n3)
      {
         b3 = true;
         edge_found = true;
         break;
      }
   }
   elist = NULL;
   for(Edge *edge; (edge = yieldNextOutEdge(host, n1, &elist, 5, 0)) != NULL && !edge_found;)
   {
      if(edge != NULL && edgeTarget(edge) == n3)
      {
         b3 = true;
         edge_found = true;
         break;
      }
   }
   if(!edge_found) b3 = false;
}

static bool match_n0(Morphism *morphism);
static bool match_e1(Morphism *morphism);
static bool match_n3(Morphism *morphism, Edge *host_edge);
static bool match_e0(Morphism *morphism);
static bool match_n2(Morphism *morphism, Edge *host_edge);
static bool match_e2(Morphism *morphism);
static bool match_n1(Morphism *morphism, Edge *host_edge);

bool matchMain_rec(Morphism *morphism)
{
   if(host->number_of_nodes < 4 || host->number_of_edges < 3) return false;
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
      if(nodeOutDegree(host_node) < 2       ||
         ((nodeOutDegree(host_node) + nodeInDegree(host_node)) < 2)) continue;

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
         if(match_e1(morphism)) return true;
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

static bool match_e1(Morphism *morphism)
{
   /* Start node is the already-matched node from which the candidate
      edges are drawn. End node may or may not have been matched already. */
   Node *host_node = lookupNode(morphism, 0);
   Node *end_node = lookupNode(morphism, 3);
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
         /* Matching integer variable 5. */
         if(item->atom.type != 'i') break;
         result = addIntegerAssignment(morphism, 5, item->atom.num);
         if(result >= 0)
         {
            new_assignments += result;
            /* Update global booleans for the variable's predicates. */
            evaluatePredicate1(morphism);
            if(!evaluateCondition())
            {
               /* Reset the boolean variables in the predicates of this variable. */
               b1 = true;
               break;
            }
         }
         else break;
         match = true;
      } while(false);

      if(match)
      {
         addEdgeMap(morphism, 1, host_edge, new_assignments);
         setEdgeMatched(host_edge);
         if(match_n3(morphism, host_edge)) return true;
         else
         {
            removeEdgeMap(morphism, 1);
            clearEdgeMatched(host_edge);
         }
      }
      else removeAssignments(morphism, new_assignments);
   }

   return false;
}

static bool match_n3(Morphism *morphism, Edge *host_edge)
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
      /* Matching string variable 3. */
      if(item->atom.type != 's') break;
      result = addStringAssignment(morphism, 3, item->atom.str);
      if(result >= 0)
      {
         new_assignments += result;
      }
      else break;
      match = true;
   } while(false);

   if(match)
   {
      addNodeMap(morphism, 3, host_node, new_assignments);
      setNodeMatched(host_node);
      /* Update global booleans representing the node's predicates. */
      evaluatePredicate3(morphism);
      bool next_match_result = false;
      if(evaluateCondition()) next_match_result = match_e0(morphism);
      if(next_match_result) return true;
      else
      {
         /* Reset the boolean variables in the predicates of this node. */
         b3 = false;
         removeNodeMap(morphism, 3);
         clearNodeMatched(host_node);
      }
   }
   else removeAssignments(morphism, new_assignments);
   return false;
}

static bool match_e0(Morphism *morphism)
{
   /* Start node is the already-matched node from which the candidate
      edges are drawn. End node may or may not have been matched already. */
   Node *host_node = lookupNode(morphism, 0);
   Node *end_node = lookupNode(morphism, 2);
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
         /* Matching integer variable 4. */
         if(item->atom.type != 'i') break;
         result = addIntegerAssignment(morphism, 4, item->atom.num);
         if(result >= 0)
         {
            new_assignments += result;
            /* Update global booleans for the variable's predicates. */
            evaluatePredicate0(morphism);
            if(!evaluateCondition())
            {
               /* Reset the boolean variables in the predicates of this variable. */
               b0 = true;
               break;
            }
         }
         else break;
         match = true;
      } while(false);

      if(match)
      {
         addEdgeMap(morphism, 0, host_edge, new_assignments);
         setEdgeMatched(host_edge);
         if(match_n2(morphism, host_edge)) return true;
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

static bool match_n2(Morphism *morphism, Edge *host_edge)
{
   Node *host_node = edgeTarget(host_edge);

   if(nodeMatched(host_node)) return false;
   if(host_node->label.mark != 0) return false;
      if(nodeInDegree(host_node) < 2       ||
         ((nodeOutDegree(host_node) + nodeInDegree(host_node)) < 2)) return false;

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
      /* Matching string variable 2. */
      if(item->atom.type != 's') break;
      result = addStringAssignment(morphism, 2, item->atom.str);
      if(result >= 0)
      {
         new_assignments += result;
      }
      else break;
      match = true;
   } while(false);

   if(match)
   {
      addNodeMap(morphism, 2, host_node, new_assignments);
      setNodeMatched(host_node);
      if(match_e2(morphism)) return true;
      else
      {
         removeNodeMap(morphism, 2);
         clearNodeMatched(host_node);
      }
   }
   else removeAssignments(morphism, new_assignments);
   return false;
}

static bool match_e2(Morphism *morphism)
{
   /* Start node is the already-matched node from which the candidate
      edges are drawn. End node may or may not have been matched already. */
   Node *host_node = lookupNode(morphism, 2);
   Node *end_node = lookupNode(morphism, 1);
   if(host_node == NULL) return false;
   EdgeList *elistpos;
   elistpos = NULL;
   for(Edge *host_edge; (host_edge = yieldNextInEdge(host, host_node, &elistpos, 0, false)) != NULL;)
   {
      if(edgeMatched(host_edge)) continue;
      if(edgeSource(host_edge) == edgeTarget(host_edge)) continue;
      if(host_edge->label.mark != 0) continue;

      /* If the end node has been matched, check that the edgeSource of the
       * host edge is the image of the end node. */
      if(end_node != NULL)
      {
         if(edgeSource(host_edge) != end_node) continue;
      }
      /* Otherwise, the edgeSource of the host edge should be unmatched. */
      else if(nodeMatched(edgeSource(host_edge))) continue;
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
         /* Matching integer variable 6. */
         if(item->atom.type != 'i') break;
         result = addIntegerAssignment(morphism, 6, item->atom.num);
         if(result >= 0)
         {
            new_assignments += result;
            /* Update global booleans for the variable's predicates. */
            evaluatePredicate2(morphism);
            if(!evaluateCondition())
            {
               /* Reset the boolean variables in the predicates of this variable. */
               b2 = true;
               break;
            }
         }
         else break;
         match = true;
      } while(false);

      if(match)
      {
         addEdgeMap(morphism, 2, host_edge, new_assignments);
         setEdgeMatched(host_edge);
         if(match_n1(morphism, host_edge)) return true;
         else
         {
            removeEdgeMap(morphism, 2);
            clearEdgeMatched(host_edge);
         }
      }
      else removeAssignments(morphism, new_assignments);
   }

   return false;
}

static bool match_n1(Morphism *morphism, Edge *host_edge)
{
   Node *host_node = edgeSource(host_edge);

   if(nodeMatched(host_node)) return false;
   if(host_node->label.mark != 0) return false;
      if(nodeOutDegree(host_node) < 1       ||
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
      /* Update global booleans representing the node's predicates. */
      evaluatePredicate3(morphism);
      if(evaluateCondition())
      {
         /* All items matched! */
         return true;
      }
      else
      {
         /* Reset the boolean variables in the predicates of this node. */
         b3 = false;
         removeNodeMap(morphism, 1);
         clearNodeMatched(host_node);
      }
   }
   else removeAssignments(morphism, new_assignments);
   return false;
}

void applyMain_rec(Morphism *morphism, bool record_changes)
{
   string var_1 = getStringValue(morphism, 1);
   string var_3 = getStringValue(morphism, 3);
   Edge *host_edge;
   Node *source, *target;
   source = lookupNode(morphism, 1);
   target = lookupNode(morphism, 3);
   HostLabel label;
   unsigned short list_var_length0 = 0;
   unsigned short list_length0 = list_var_length0 + 1;
   HostAtom array0[list_length0];
   int index0 = 0;

   unsigned int length0 = 0;
   length0 += strlen(var_1);
   length0 += strlen(var_3);
   char host_string0[length0 + 1];
   strcpy(host_string0, var_1);
   strcat(host_string0, var_3);
   host_string0[length0] = '\0';

   array0[index0].type = 's';
   array0[index0++].str = host_string0;
   if(list_length0 > 0)
   {
      HostList *list0 = makeHostList(array0, list_length0, false);
      label = makeHostLabel(0, list_length0, list0);
   }
   else label = makeEmptyLabel(0);

   host_edge = addEdge(host, label, source, target);
   /* If the edge array size has not increased after the edge addition, then
      the edge was added to a hole in the array. */
   if(record_changes)
      pushAddedEdge(host_edge);
   /* Reset the morphism. */
   clearMatched(morphism);
   initialiseMorphism(morphism);
}

