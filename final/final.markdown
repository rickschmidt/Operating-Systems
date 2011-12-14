#Memory

* Next used mapped memory and virtual memory
* Each task had 4GBs of mapped virtual memory to operate in
* Next used what it called *demand paging* 
	* Only the page that references the address of the active process needs to be in physical memory. 
	* If not the kernel would if necessary remove the oldest referenced page from memory and move then move the new one in
* The developer documentation claims that this process allows *extremely large* applications to run on next hardware.

* Memory was conserved in mach thorough its implementation of `fork()`
* Instead of copying all of a parents address space to the child memory was only copied when a child requested 