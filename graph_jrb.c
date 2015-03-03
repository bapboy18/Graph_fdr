#include "jrb.h"

typedef JRB Graph;

Graph createGraph();
void addEdge(Graph graph, int v1, int v2);
int adjacent(Graph graph, int v1, int v2);
int getAdjacentVertices(Graph graph, int v, int* output);
void dropGraph(Graph graph) ;

main(){

}

Graph createGraph(){
return make_jrb();
}

int adjacent(Graph graph, int v1, int v2){
  JRB node, tree;
  node = jrb_find_int(graph, v1);
  if(node == NULL)
    return 0;
  tree = (JRB)jval_v(node->val);
  if(jrb_find_int(tree,v2) == NULL)
    return 0;
  else return 1;
}

void addEdge(Graph graph, int v1, int v2){
  JRB node, tree;
  if(!adjacent(graph,v1,v2)){
    node = jrb_find_int(graph,v1);
    if(node == NULL){
      tree = make_jrb();
      jrb_insert_int(graph,v1, new_jval_v(tree));
    }else{
    tree = (JRB)jval_v(node -> val);
    }
    jrb_insert_int(tree, v2,new_javal_i(1));
  }
  if(!adjacent(graph,v2,v1)){
    node = jrb_find_int(graph,v2);
    if(node == NULL){
      tree = make_jrb();
      jrb_insert_int(graph,v2, new_jval_v(tree));
    }else{
      tree = (JRB)jval_v(node ->val);
    }
    jrb_insert_int(tree,v1,new_jval_i(1));
  }
}

int getAdjcentVertices()
