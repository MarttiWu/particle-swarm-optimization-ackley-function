# Particle Swarm Optimization



# Ackley Function



# Usage

Open terminal

    make
    
1. Run directly in the terminal by typing the following:

        #./main [algo] [runs] [iter] [filename] [population] [W] [alpha1] [alpha2] [Dimension]
        ./main pso 30 100 "" 20 0.2 1.49445 1.49445 2
    
2. Or if you want to run multiple times, just by opening the "search.sh" and add whatever you want and run by typing


        ./search.sh
    in the terminal.
    
# Customize

You can change the iteration block by modifying 

        const int block=10;
in "execute.hpp".

# Results

![alt text]()


