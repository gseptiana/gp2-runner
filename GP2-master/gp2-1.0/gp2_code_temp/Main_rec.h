#include "graph.h"
#include "label.h"
#include "graphStacks.h"
#include "parser.h"
#include "morphism.h"

bool matchMain_rec(Morphism *morphism);

void applyMain_rec(Morphism *morphism, bool record_changes);
