
//This was created by Mali, student from UCF//
struct TraceCache
{
    bool valid;			//Specifies if this cache line is valid//
    unsigned int tag;		//Stores the tag (tag of the first PC)//
    unsigned int *flags;	//Stores 1 or 0 (Taken or Not Taken) for branch//
    unsigned int mask;		//Specifies # of branches, and if last instr is branch//	
    unsigned int fall_addr;	//If last instr is branch, its fall through address//
    unsigned int target_addr;	//If last instr is branch, its target address//
    unsigned int n_insts;	//Number of Instr in Trace Cache Line//
    unsigned int *pc;		//The PCs of each instruction//
    unsigned int *b_pc;		//The PCs of branch instructions//
    unsigned int *pred_tag;	//???//
    bool last_taken;		//??If last instr is branch, is it taken or not taken//
};


