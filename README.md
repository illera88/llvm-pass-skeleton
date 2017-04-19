# llvm-pass-skeleton

A completely useless LLVM pass.

Build:

    $ cd llvm-pass-skeleton
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    $ cd ..

Run:

    $ clang -Xclang -load -Xclang build/skeleton/libSkeletonPass.* test.c
    
This will generate a `.ll` file that will contain the llvm bytecode. We can compile to binary using clang:
    
    $clang something.ll -o out
    
But we can get the assembly (`.s`) doing:
     
     $llc something.ll
