// copyright 2017 Lanting Guo

/** Generate LLVM IR from helloworld.c using LLVM

 */

// #include "llvm/ADT/APInt.h"
// #include "llvm/IR/Verifier.h"
// #include "llvm/ExecutionEngine/ExecutionEngine.h"
// #include "llvm/ExecutionEngine/GenericValue.h"
// #include "llvm/ExecutionEngine/MCJIT.h"
// #include "llvm/IR/Argument.h"
// #include "llvm/IR/BasicBlock.h"
// #include "llvm/IR/Constant.h"
// #include "llvm/IR/Constants.h"
// #include "llvm/IR/DerivedTypes.h"
// #include "llvm/IR/InstrTypes.h"
// #include "llvm/IR/Instruction.h"
// #include "llvm/IR/Instructions.h"
// #include "llvm/IR/Type.h"
// #include "llvm/IR/Intrinsics.h"
// #include "llvm/Support/Casting.h"
// #include "llvm/Support/TargetSelect.h"
// #include "llvm/Support/raw_ostream.h"

#include <vector>
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"

int main(int argc, char *argv[]) {
  llvm::LLVMContext context;
  llvm::Module* module =  new llvm::Module("Top", context);
  llvm::IRBuilder<> builder(context);
  llvm::FunctionType* funcType =
      llvm::FunctionType::get(builder.getVoidTy(), false);
  llvm::Function* mainFunc = llvm::Function::Create(funcType,
             llvm::Function::ExternalLinkage, "main", module);
  llvm::BasicBlock *bb =
      llvm::BasicBlock::Create(context, "entrypoint", mainFunc);
  builder.SetInsertPoint(bb);
  llvm::Value *str = builder.CreateGlobalStringPtr("Hello World!\n");
  std::vector<llvm::Type *> printfArgs;
  printfArgs.push_back(builder.getInt8Ty()->getPointerTo());
  llvm::ArrayRef<llvm::Type *> arrayRef(printfArgs);
  llvm::FunctionType *printftype =
      llvm::FunctionType::get(builder.getInt32Ty(), arrayRef, false);
  llvm::Constant *printfFunc =
      module->getOrInsertFunction("printf", printftype);
  builder.CreateCall(printfFunc, str);
  builder.CreateRetVoid();
  module->dump();
  return 0;
}


