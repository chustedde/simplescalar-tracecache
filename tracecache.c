/*All functions that are usefule for working with tracecache*/

#include <stdio.h>
#include <stdlib.h>

#include "tracecache.h"
#include "bpred.h"
#include "machine.h"


/*returns index in trace cache where pc can be found*/
int search_tc(int pc, struct TraceCache *tc, int size, struct bpred_t *pred)
{
	int i, j, prediction;
	enum md_opcode op;
	md_inst_t inst;
	md_addr_t pred_PC;
	
	for(i = 0; i < size; i++)
	{
		if(tc[i].valid && pc == tc[i].pc[0])
			//search all branches//
			for(j = 0; j < tc[i].mask >> 0x01; j++)
			{
				/* pre-decode instruction, used for bpred stats recording */
				MD_FETCH_INST(inst, mem, tc[i].b_pc[j]);
				MD_SET_OPCODE(op, inst);
				pred_PC = bpred_lookup(pred,
					/* branch address */tc[i].b_pc[j],
					/* target address *//* FIXME: not computed */0,
					/* opcode */op,
					/* call? */MD_IS_CALL(op),
					/* return? */MD_IS_RETURN(op),
					/* updt */&(TUNeedDirUpdate),
					/* RSB index */NULL);
				if(pred_PC != tc[i].b_pc[j] + sizeof(md_inst_t))
					return -1;				
			}
			
			return i;	
	}
	
	return -1;
}


	  
	  
	  else
	    fetch_pred_PC = 0;

	  /* valid address returned from branch predictor? */
	  if (!fetch_pred_PC)
	    {
	      /* no predicted taken target, attempt not taken target */
	      fetch_pred_PC = fetch_regs_PC + sizeof(md_inst_t);
	    }
	  else
	    {
	      /* go with target, NOTE: discontinuous fetch, so terminate */
	      branch_cnt++;
	      if (branch_cnt >= fetch_speed)
		done = TRUE;
	    }

