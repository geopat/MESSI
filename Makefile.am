AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS =  ${ACLOCAL_FLAGS}

lib_LIBRARIES	= lib/libads.a
# lib_libads_a_SOURCES = src/ads/isax_file_loaders.c src/ads/isax_first_buffer_layer.c src/ads/isax_index.c src/ads/isax_node.c src/ads/isax_node_buffer.c src/ads/isax_node_record.c src/ads/isax_node_split.c src/ads/isax_query_engine.c src/ads/isax_visualize_index.c src/ads/pqueue.c src/ads/sax/sax.c src/ads/sax/ts.c src/ads/inmemory_query_engine.c src/ads/parallel_inmemory_query_engine.c src/ads/inmemory_index_engine.c src/ads/parallel_index_engine.c src/ads/parallel_query_engine.c src/ads/inmemory_topk_engine.c
lib_libads_a_SOURCES = src/ads/isax_file_loaders.c src/ads/isax_first_buffer_layer.c src/ads/isax_index.c src/ads/isax_node.c src/ads/isax_node_buffer.c src/ads/isax_node_record.c src/ads/isax_node_split.c src/ads/isax_visualize_index.c src/ads/pqueue.c src/ads/sax/sax.c src/ads/sax/ts.c src/ads/inmemory_query_engine.c src/ads/parallel_inmemory_query_engine.c src/ads/inmemory_index_engine.c src/ads/parallel_index_engine.c src/ads/prioq.c src/ads/common.c src/ads/gc/gc.c src/ads/gc/ptst.c 
lib_libads_a_CFLAGS =-I/opt/local/include -Iinclude/ -march=native -mavx -mavx2 -msse3 -fopenmp -DINTEL -DCACHE_LINE_SIZE=`getconf LEVEL1_DCACHE_LINESIZE` -DMCX16 -std=gnu99 -fcommon

# bin_PROGRAMS	= bin/query-ads-index bin/ads bin/meminfo bin/ads-server
bin_PROGRAMS	= bin/ads

# bin_query_ads_index_SOURCES = src/utils/query-ads-index.c
# bin_query_ads_index_CFLAGS = -I/opt/local/include -Iinclude/ -I/usr/local/include/ -march=native -std=gnu99
# bin_query_ads_index_LDADD = -lm -lreadline -lads -lm -lpthread
# bin_query_ads_index_LDFLAGS = -L/opt/local/lib -Llib/ -mavx -mavx2 -msse3

# bin_meminfo_SOURCES = src/utils/meminfo.c
# bin_meminfo_CFLAGS = -I/opt/local/include -Iinclude/ -I/usr/local/include/ -march=native -std=gnu99
# bin_meminfo_LDADD = -lm -lreadline -lads -lm -lpthread 
# bin_meminfo_LDFLAGS = -L/opt/local/lib -Llib/ -mavx -mavx2 -msse3

bin_ads_SOURCES = src/utils/ads.c
bin_ads_CFLAGS = -I/opt/local/include -Iinclude/ -I/usr/local/include/ -march=native -std=gnu99 -fcommon 
bin_ads_LDADD = -lm -lreadline -lads -lm -lpthread
bin_ads_LDFLAGS = -L/opt/local/lib -Llib/ -mavx -mavx2 -msse3 -fopenmp

# bin_ads_server_SOURCES = src/utils/ads-server.c
# bin_ads_server_CFLAGS = -I/opt/local/include -Iinclude/ -I/usr/local/include/ -march=native -std=gnu99
# bin_ads_server_LDADD = -lm -lreadline -lads -levent -lm -lpthread 
# bin_ads_server_LDFLAGS = -L/opt/local/lib -Llib/ -L/usr/local/lib/ -mavx -mavx2 -msse3 
