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

namespace {
class MyFunctionPass: public FunctionPass {
 public:
  MyFunctionPass(): FunctionPass(ID) {}
  virtual bool runOnFunction(llvm::Function &F) override {
    if (F.getName().startswith("hello")) {
      llvm::outs() << "Function name starts with hello. \n";
    }
    return false;
  }
  static char ID;
};
}  //  namespace
char MyFunctionPass::ID = 'a';
static llvm::RegisterPass<MyFunctionPass> global_("test_llvm-guolanting",
                                                  "test llvm", false, false);
