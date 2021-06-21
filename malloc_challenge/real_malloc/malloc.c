#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mmap_from_system(size_t size);
void munmap_to_system(void *ptr, size_t size);

typedef struct metadata_t {
  size_t size;
  struct metadata_t *next;
} metadata_t;

//freeに使う
typedef struct heap_t {
  metadata_t *free_head;
  metadata_t dummy;
} heap_t;

heap_t heap;

// Add a free slot to the beginning of the free list.
void add_to_free_list(metadata_t *metadata) {
  assert(!metadata->next);
  metadata->next = heap.free_head;
  heap.free_head = metadata;
}

// Remove a free slot from the free list.
void remove_from_free_list(metadata_t *metadata, metadata_t *prev) {
  if (prev) {
    prev->next = metadata->next;
  } else {
    heap.free_head = metadata->next;
  }
  metadata->next = NULL;
}

// my_initialize() is called only once at the beginning of each challenge.
void my_initialize() {
  // Implement here!
  heap.free_head = &heap.dummy;
  heap.dummy.size = 0;
  heap.dummy.next = NULL;
}

// my_malloc() is called every time an object is allocated. |size| is guaranteed
// to be a multiple of 8 bytes and meets 8 <= |size| <= 4000. You are not
// allowed to use any library functions other than mmap_from_system /
// munmap_to_system.
void *my_malloc(size_t size) {
  metadata_t *best_fit = NULL;
  metadata_t *best_fit_prev = NULL;
  metadata_t *metadata = heap.free_head;
  metadata_t *prev = NULL;
  //-----------------------
  // Best-fit
  //-----------------------
  int cnt = 0;
  while (metadata) {
    if(metadata->size >= size){
      //最初に見つけた領域をbest_fitに入れる
      if(cnt == 0){
        // ALEX_COMMENT:  this is good, the initialization is done on the first free element.
        //                however, you pay the cost of this "if" running on every single iteration.
        //                can you think about a way to remove this initialization from the loop?
        best_fit = metadata;
        best_fit_prev = prev;
        cnt++;
      }
      //より小さな(適切な)領域をbest_fitに入れる
      if(best_fit->size > metadata->size){
        best_fit = metadata;
        best_fit_prev = prev;
      }
    }
    prev = metadata;
    metadata = metadata->next;
  }

  if (!best_fit) { //確保したいサイズに見合う空きがない
    // There was no free slot available. We need to request a new memory region
    // from the system by calling mmap_from_system().
    //
    //     | metadata | free slot |
    //     ^
    //     metadata
    //     <---------------------->
    //            buffer_size
    size_t buffer_size = 4096;
    metadata_t *metadata =(metadata_t *)mmap_from_system(buffer_size);
    metadata->size = buffer_size - sizeof(metadata_t);
    metadata->next = NULL;
    // Add the memory region to the free list.
    add_to_free_list(metadata);
    // Now, try my_malloc() again. This should succeed.
    return my_malloc(size);
  }

  // |ptr| is the beginning of the allocated object.
  //
  // ... | metadata | object | ...
  //     ^          ^
  //     metadata   ptr
  void *ptr = best_fit + 1;
  size_t remaining_size = best_fit->size - size;
  best_fit->size = size;
  // Remove the free slot from the free list.
  remove_from_free_list(best_fit, best_fit_prev);

  if (remaining_size > sizeof(metadata_t)) {
    // Create a new metadata for the remaining free slot.
    //
    // ... | metadata | object | metadata | free slot | ...
    //     ^          ^        ^
    //     metadata   ptr      new_metadata
    //                 <------><---------------------->
    //                   size       remaining size
    metadata_t *new_metadata = (metadata_t *)((char *)ptr + size);
    new_metadata->size = remaining_size - sizeof(metadata_t);
    new_metadata->next = NULL;
    // Add the remaining free slot to the free list.
    add_to_free_list(new_metadata);
  }
  return ptr;
}

// my_free() is called every time an object is freed.  You are not allowed to
// use any library functions other than mmap_from_system / munmap_to_system.
void my_free(void *ptr) {
  // Implement here!  munmap_to_system(ptr, 4096);
  // Look up the metadata. The metadata is placed just prior to the object.
  //
  // ... | metadata | object | ...
  //     ^          ^
  //     metadata   ptr
  metadata_t *metadata = (metadata_t *)ptr - 1;
  // Add the free slot to the free list.
  add_to_free_list(metadata);
}

void my_finalize() {
  // Implement here!
}

void test() {
  // Implement here!
  //assert(1 == 1); /* 1 is 1. That's always true! (You can remove this.) */
}
