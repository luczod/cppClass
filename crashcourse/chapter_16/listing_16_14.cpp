// Listing 16-14: A program opening the file lunchtime.txt
// and appending a message to it.
#include <fstream>

using namespace std;

int main() {
  ofstream file{ "lunchtime.txt", ios::out | ios::app };
  file << "Time is an illusion." << endl;
  file << "Lunch time, " << 2 << "x so." << endl;
}

/* the flags "ios::out | ios::app". Because this combination of flags appends output,
any data you send through the output operator into this file stream gets
appended to the end of the file. */
