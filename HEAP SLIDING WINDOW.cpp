#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
/* This function heapifies heap after removal of root  
or at time of building heap from an array */
void max_heapify_ptr(heap_node * a[], int i, int len){
        int largest =i;
        int left, right;
 
        left = left_child(i);
        right = right_child(i);
        if(left <= len && a[i]->data <a[left]->data){
                largest = left;
        }
        if(right <= len && a[largest]->data < a[right]->data){
                largest = right;
        }
        if(largest != i){
                swap_ptr(a, i, largest);
                max_heapify_ptr(a, largest, len);
        }
}
 
/* Building heap from given elements */
void build_max_heap_ptr(heap_node *a[], int len){
        int i = len/2 +1;
        for(; i>=0; i--){
                max_heapify_ptr(a,i, len);
        }
}
 
/* This function allocates node of heap */
heap_node * create_node(int data){
        heap_node *node = (heap_node *)(malloc)(sizeof(heap_node));
        if(node){
                node->data = data;
        }
        return node;
 
}
 
/* This function is real implementation of the sliding window algorithm */
void slide_window(int buffer[], int N, int K, int buffer_len){
 
    int i =0, j =0,s;
    heap_node *max_heap[K];
 
    for(j=0 ; j + N < buffer_len; j++){
      /* Window starts at index 0 and is of size N */
       printf("\n Current window : \n" );
       for(s =j; s<j+N; s++){
           printf("%d ", buffer[s]);
       }
       printf("\n");
       /* Put K element from N element window */
       for(i=0;i<K; i++){
       /* Since we wold be doing for every window, avoiding reallocation of node */
           if(max_heap[i]){
                max_heap[i]->data = buffer[i+j];
            }
            else{
                max_heap[i] = create_node(buffer[i+j]);
            }
        }
        /* Build min heap with those entered elements */
         build_max_heap_ptr(max_heap,K-1);
         for(i =0; i<K; i++){
              printf("%d ", max_heap[i]->data);
         }
         printf("\n");
 
        /*Now for all remaining N-K-1 elements in window, 
         check if they fit in max heap */
         for(i =K+j; i< N+j; i++){
             heap_node * root = max_heap[0];
             if(buffer[i] < root->data){
                 root->data = buffer[i];
                 max_heapify_ptr(max_heap, 0, K-1);
              }
          }
          /*Print the current max heap, it will contain K smallest 
            element in current window */
          for(i =0; i<K; i++){
              printf("%d", max_heap[i]->data);
          }
        }
}
/* Driver Program to execute above code */
int main(){
   int buffer[10] = {1,4,5,6,3,2,4,8,9,6};
 
   int K= 4;
   int N =5;
   
   int size = sizeof(buffer)/ sizeof(buffer[0]);
   
   slide_window(buffer,N, K,size);
   return 0;
}