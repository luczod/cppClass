### Chapter 21: Writing Applications

Google’s Chrome Browser launches many processes to service a single browser session. Web apps and plug-ins, for example, run in separate
processes, so if they crash, the entire browser doesn’t crash. Also, by running the browser’s rendering engine in a separate process, any security vulnerabilities become more difficult to exploit because Google locks down that process’s permissions in what is known as a **sandboxed environment**.

The preprocessor is a program that applies simple transformations to source code before compilation. You give instructions to the preprocessor using preprocessor directives. All preprocessor directives begin with a **hash mark (#)**. The preprocessor also supports other directives. The most common is **the macro**, which is a fragment of code that’s been given a name. Ex: #define MESSAGE "LOL"

Aside from using #include, you should use the preprocessor as little as possible. The preprocessor is extremely primitive and will cause difficultto-debug errors if you lean on it too heavily. This is evident with #include, which is **a simple copy-and-paste command**.

You can allow C code to incorporate functions and variables from your programs using language linkage. Language linkage instructs the compiler to generate symbols with a specific format friendly to another target language.

#### Contents

- template: A framework for investigating program termination and cleanup facilities
- atexit: Registering an atexit callback
- exit: Invoking std::exit
- abort: Calling std::abort
- ping: Using std::system to invoke the ping utility
- getenv: Using std::getenv to retrieve the path variable
- sigint: Registering for keyboard interrupts with std::signal
- program_options: Using Boost ProgramOptions to generate a nicely formatted help dialog
