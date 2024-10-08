
#ifndef al_inmemory_query_engine_h
#define al_inmemory_query_engine_h
#include "../../config.h"
#include "../../globals.h"
#include "sax/ts.h"
#include "sax/sax.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "isax_index.h"
#include "isax_query_engine.h"
#include "isax_node.h"
#include "pqueue.h"
#include "isax_first_buffer_layer.h"
#include "ads/isax_node_split.h"


float calculate_node_distance_inmemory (isax_index *index, isax_node *node, ts_type *query , float bsf);
float calculate_node_distance_inmemory_ekosmas (isax_index *index, isax_node *node, ts_type *query , float bsf);
float calculate_node_distance_inmemory_ekosmas_lf (isax_index *index, isax_node *node, ts_type *query, float bsf, const char parallelism_in_subtree);
float calculate_node_distance_inmemory_geopat_lf (isax_index *index, isax_node_single_buffer *node, ts_type *query, float bsf, const char parallelism_in_subtree) ;
float calculate_node_distance2_inmemory (isax_index *index, isax_node *node, ts_type *query, ts_type *paa, float bsf);
float calculate_node_distance2_inmemory_ekosmas (isax_index *index, isax_node *node, ts_type *query, ts_type *paa, float bsf);
float calculate_node_distance2_inmemory_geopat (isax_index *index, isax_node_record *record, ts_type *query, ts_type *paa, float bsf);
float calculate_node_distance2_inmemory_geopat2(isax_index *index, query_result *n, ts_type *query, ts_type *paa, float bsf,const char parallelism_in_subtree) ;
float calculate_eyclidian_distance(isax_index *index, ts_type *query, float bsf,unsigned long position);
float calculate_node_distance2_inmemory_ekosmas_lf (isax_index *index, query_result *n, ts_type *query, ts_type *paa, float bsf, const char parallelism_in_subtree);
query_result  approximate_search_inmemory_pRecBuf (ts_type *ts, ts_type *paa, isax_index *index);
query_result  approximate_search_inmemory_pRecBuf_ekosmas (ts_type *ts, ts_type *paa, isax_index *index);
query_result  approximate_search_inmemory_pRecBuf_ekosmas_lf (ts_type *ts, ts_type *paa, isax_index *index, const char parallelism_in_subtree);
query_result  approximate_search_inmemory_pRecBuf_ekosmas_lf_geopat(ts_type *ts, ts_type *paa, isax_index *index, const char parallelism_in_subtree);
float calculate_minimum_distance_inmemory (isax_index *index, isax_node *node, ts_type *raw_query, ts_type *query);

struct args_in 
{
    unsigned int i;
    unsigned long from;
    unsigned long to;
    float bsf;
    ts_type *paa;
    isax_index *index;
};

float * rawfile;
#endif
