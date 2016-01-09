# Distributed Dictionary
This program is written in C, for practising purpose mainly.

## Main Component
 - UI
    - text-based
 - data object
    - unique id
    - key list
    - key value pair
 - master
    - request to create/get/edit object
    - hold all slave 'contact'
    - nested master (not in this stage)
 - slave
    - store data object
    - register to master when startup
    - listen to master
    - peer communication (not in this stage)
    - 'data storing load balancing' (not in this stage)
       - get copy from other slave when having
       - migrate data object to others before shutdown
       - handle synchronization when restore
 - distributed node (not in this stage)
    - able to work without master
