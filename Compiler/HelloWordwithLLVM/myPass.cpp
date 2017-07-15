// copyright 2017 Lanting Guo

/** Create a working compiler with the LLVM framework, Part 2
    didn't try clang
 https://www.ibm.com/developerworks/library/os-createcompilerllvm2/index.html
 */

#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Function.h"

using Function = llvm::Function;
using FunctionPass = llvm::FunctionPass;

class MyFunctionPass: public FunctionPass {
 public:
  MyFunctionPass(): FunctionPass(ID) {}
  virtual bool runOnFunction(llvm::Function &F) {
    if (F.getName().startswith("hello")) {
      llvm::outs() << "Function name starts with hello. \n";
    }
    return false;
  }
  static char ID;
};

char MyFunctionPass::ID = 'a';
static llvm::RegisterPass<MyFunctionPass> global_("test_llvm",
                                                  "test llvm", false, false);
