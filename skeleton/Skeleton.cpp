#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/Instructions.h"

using namespace llvm;

namespace {
  struct SkeletonPass : public FunctionPass {
    static char ID;
    SkeletonPass() : FunctionPass(ID) {}

    virtual bool runOnFunction(Function &F) {
		
		 for (inst_iterator It = inst_begin(F), E = inst_end(F); It != E; ++It)
			{
				//previous iterator
				inst_iterator PrevIt; 
				bool bFirst = false;
				if (It == inst_begin(F))
				{
						bFirst = true;
				}
				else
				{
						PrevIt = It;
						--PrevIt;
				}
				
				Instruction* CurrI = &(*It);

				errs() << "Processing " << *CurrI << "\n";
				
				if (isa<LoadInst>(CurrI))
				{

					/* //replace - intrinsics ID (from Intrinsics.def) and some int arguments
					replaceByIntrinsic(M, CurrI, Intrinsic::regread_i32, 1, 2);
					
					//renew iterator because we removed previous instruction to which it was pointing
					if (!bFirst)
					{
							It = ++PrevIt;
					}
					else
					{
							It = ++inst_begin(F);
					} */
				}
					
			}
		
		
      errs() << "I saw a function called " << F.getName() << "!\n";
      return false;
    }
  };
}

char SkeletonPass::ID = 0;

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerSkeletonPass(const PassManagerBuilder &,
                         legacy::PassManagerBase &PM) {
  PM.add(new SkeletonPass());
}
static RegisterStandardPasses
  RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                 registerSkeletonPass);

