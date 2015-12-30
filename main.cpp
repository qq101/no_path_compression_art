#include "ART.cpp"
#include "iostream"
#include "fstream"
using namespace std;
int main(int argc, char** argv) {
   //fib_file
   char *fib_file_name = argv[1];
   ifstream fib_stream;
   fib_stream.open(fib_file_name);
   //trace_file
   char *trace_file_name = argv[2];
   ifstream trace_stream;
   trace_stream.open(trace_file_name);
   //delete_file
   char *delete_file_name = argv[3];
   ifstream delete_stream;
   delete_stream.open(delete_file_name);

   unsigned int line = 0;
   unsigned int len;
   uintptr_t port;
   char buffer[256];
   char name[256];
   char id[8];

//Insert
   double start = gettime();
   Node* tree = NULL;
   while (fib_stream.getline(buffer, 256)) {
      sscanf(buffer, "%[^,]", name);
      sscanf(buffer, "%*[^,],%s", id);
      len = strlen(name);
      name[len] = '\0';
      port = atoi(id);
      line++;
      insert(tree, &tree, (uint8_t*)name, 0, port, len + 1);
   }
   cout << "insert line:" << line << " ,time:" << gettime() - start << endl;


//Lookup
   fib_stream.close();
   start = gettime();
   line = 0;
   while (trace_stream.getline(buffer, 256)) {
      len = strlen(buffer);
      buffer[len] = '\0';
      line++;
      uintptr_t result = lookup(tree, (uint8_t*)buffer, len + 1, 0, len + 1);
      cout << "value=" << result << endl;
   }
   cout << "lookup line:" << line << " ,time:" << gettime() - start << endl;

   trace_stream.close();
   return 0;
}
