//
//  isax_node_buffer.h
//  aisax
//
//  Created by Kostas Zoumpatianos on 4/6/12.
//  Copyright 2012 University of Trento. All rights reserved.
//

// TODO: RENAME TO ISAX_LEAF_NODE_BUFFER.H

#ifndef aisax_isax_node_buffer_h
#define aisax_isax_node_buffer_h
#include "../../config.h"
#include "../../globals.h"
#include "isax_node_record.h"

typedef struct isax_node_buffer {
    int initial_buffer_size;  
    long tmp_buffer_readers;
    // Full data:
    sax_type **full_sax_buffer;
    file_position_type **full_position_buffer;
    ts_type **full_ts_buffer;
    
    // Partial data:
    sax_type **partial_sax_buffer;
    file_position_type **partial_position_buffer;
    
    // TMP Buffers (stuff coming from splits and loads)
    // Full data:
    sax_type **tmp_full_sax_buffer;
    file_position_type **tmp_full_position_buffer;
    ts_type **tmp_full_ts_buffer;
    
    // Partial data:
    sax_type **tmp_partial_sax_buffer;
    file_position_type **tmp_partial_position_buffer;
    
    
    int full_buffer_size;
    int max_full_buffer_size;
    
    int partial_buffer_size;
    int max_partial_buffer_size;
    
    int tmp_full_buffer_size;
    int max_tmp_full_buffer_size;
    
    int tmp_partial_buffer_size;
    int max_tmp_partial_buffer_size;

} isax_node_buffer;

void destroy_node_buffer(isax_node_buffer *buffer);
void destroy_node_buffer_and_records(isax_node_buffer *node_buffer);

isax_node_buffer *init_node_buffer(int initial_buffer_size);
isax_node_buffer *clone_buffer_and_add_record_lockfree_cow(isax_node_buffer *buffer, isax_node_record *record);
isax_node_buffer *clone_buffer_and_add_record_lockfree_cow_geopat(isax_node_buffer *buffer,int size ,isax_node_record *record);

enum response add_to_node_buffer(isax_node_buffer *node_buffer, 
                                 isax_node_record *record, 
                                 int sax_segments, int ts_segments);
enum response add_to_node_buffer_lockfree(isax_node_buffer *node_buffer, 
                                 isax_node_record *record, 
                                 unsigned long next_buf_pos);
 enum response  add_to_node_buffer_lockfree_geopat(isax_node_buffer *node_buffer, 
                                 isax_node_record *record, 
                                 int next_buf_pos);                                
#endif
