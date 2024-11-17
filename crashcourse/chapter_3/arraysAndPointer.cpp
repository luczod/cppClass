#include <cstdio>

int key_to_the_universe[]{3, 6, 9};
// arrays decay into pointers to their first element
int* key_ptr = key_to_the_universe;  // Points to 3

struct College {
  char name[256];
};

// parameter is a pointer-to-College
void print_name(College* college_ptr) {
  printf("%s College\n", college_ptr->name);
}

void decay_array() {
  College best_colleges[] = {"Magdalen", "Nuffield", "Kellogg"};
  print_name(best_colleges);  // Magdalen College
}

// Handling Decay
// add the array’s length
void print_names(College* colleges, size_t n_colleges) {
  for (size_t i = 0; i < n_colleges; i++) {
    printf("%s College\n", colleges[i].name);
  }
}

void handler_decay() {
  College oxford[] = {"Magdalen", "Nuffield", "Kellogg"};
  print_names(oxford, sizeof(oxford) / sizeof(College));
}

int main() { handler_decay(); }
