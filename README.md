# OS_sharedMemory

Given Project contains following Solution :-
- Implement a solution to the bounded-buffer producer-consumer problem using only two shared
variables ‘in’ and ‘out’ (apart from the shared buffer itself), which indicate the positions in the buffer array where / from where the next item to be inserted / retrieved by the producer and the consumer process respectively. 
- Note that in this solution, the buffer can contain maximum (BUFFERSIZE-1) items.
In your solution, do not use busy waiting based iterative loops (as shown in book), rather, use the pause() and kill() system calls to block and unblock a process.
- Note that, in this solution, although in and out are shared variables, none of them are updated by multiple processes, rather, in is updated only by the producer process and out is updated only by the consumer process. Hence, we do not need to synchronize the access of these two shared variables.

Now, implement the following on the top of the above solution :-

- Producer process, on each iteration, takes details of a student (name, enroll no, section, age etc.) from the user and puts this data as an item into the shared buffer. 
- The consumer process on the other hand, on each of its iteration, retrieves a data item from the buffer and saves it in a CSV file on the disk, where the fields (name, enroll no. etc.) of a data-item are stored in comma-separated format (as usually stored in CSV).

## HOW TO RUN

Type the following commands in sequence

`git clone https://github.com/pradhuman1/OS_sharedMemory.git`<br />
`cd OS_sharedMemory`<br />
`gcc -o consumer consumer.c`<br />
`./consumer`<br />

Now open one more terminal and enter the following commands

`cd OS_sharedMemory`<br />
`gcc -o producer producer.c`<br />
`./producer`<br />

Now you are good to go.Enter details in producer program and you will see them printed in consumer
