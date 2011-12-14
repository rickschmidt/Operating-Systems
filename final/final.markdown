#Memory

* Next used mapped memory and virtual memory
* Each task had 4GBs of mapped virtual memory to operate in
* Next used what it called *demand paging* 
	* Only the page that references the address of the active process needs to be in physical memory. 
	* If not the kernel would if necessary remove the oldest referenced page from memory and move then move the new one in
* The developer documentation claims that this process allows *extremely large* applications to run on next hardware.

* Memory was conserved in mach thorough its implementation of `fork()`
* Instead of copying all of a parents address space to the child memory was only copied when a child requested 



#History
* NeXT Computer was founded by Steve Jobs after being ousted from Apple.
* They developed an operating system that originally ran on NeXT hardware only
* The computers themselves were designed to be work stations, high end machines that were suitable for scientific work in academia and also to be affordable to college students (still pretty expensive).  
*IMAGE OF CUBE


#History
* In 1993 the computer stopped manufacturing computers and became NeXT Software. 
* The operating system and development tools were sold under the name NeXTStep and later some parts were named openStep
* Eventually the operating system was ported from motorola to intel hardware.
* Sir Tim Berners-Lee  wrote the first web browser and web server on the NeXT platform.


#Scheduler
* Mach uses a time sharing scheduler (mainly)
* Each thread is assigned a priority between 0-31
* Blocking or long running threads have their priority decreased
* Threads have three priorities (base, current, max)
* Along with the time sharing policy next had an incomplete implementation for interactive scheduling and a non recommended fixed scheduling policy.

#Mutual Exclusion
* Next through Mach uses a c style mutex lock for memory protection

		`mutex_lock(m);
		count += 1;	
		mutex_unlock(m);`
		
* There was also a framework called Mach Kit which provided a form of mutual exclusion
"Define various kinds of locks that can be useful for protecting critical sections of code in drivers and multithreaded applications"

#FileSystem
* NextStep used the Unix File System (UFS)
* Continued support through current versions of OS X (10.5+ cannot be installed on UFS)

#Webobjects
* A major component of the Next Operating System was WebObjects
* WebObjects was a server technology that support Object Oriented programming in either Java or Objective C
* WebObjects was adopted by several large companies in the mid 90s but adoption quickly slowed after Apple's acquistion of NeXT
* Originally a license was $50K 
* Apple included them in the Dev Tools for free in 2005 and later dropped support.
* Apple used WebObjects to host the iTunes Stores (Rumor: Dropped in 2009)

#Characteristics
* Objective C along with C,C++
* Object Oriented Application Development
* WYSIWYG Interface Builder



#Coda
* Apple on the brink of bankruptcy purchased Next in December of 1996
* NeXT was no longer developed after this although betas are in circulation of the 4.0 release
* In 1996 Apple was losing big time to Windows.  OS 9 supported cooperative multitasking and was really only or a single user.
* There was a project within Apple to write an all new Operating System codenamed "Project Copland" which would support many of the features in NeXT
* Copland was scrapped and work began OS X 
* Cocoa and Cocoa Touch classes are all still prefixed with the NS namespace.
