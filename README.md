Usage:  
LD\_PRELOAD=/path/to/cudam.so ./a.out

Should replace all calls to new, new[] with cudaMallocManaged() w/o source changes. 
