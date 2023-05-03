# Test task for AME intern position

## Main Task №1
1. Install NS-3 and compile it.
2. Make a minimal LTE scenario using the NS-3 documentation:
    - There are eNB and two Ue.
    - Full Buffer traffic (packets go in both directions endlessly).
    - The LTE module is configured with the pf-ff-mac-scheduler packet scheduler.
    - The LTE module is configured to display key characteristics from Rlc and MAC levels.
3. Run the script and get the output of key characteristics(KPI, Key Performance Indicators).

## Main Task №2
+ Write a script that, based on the obtained output of key characteristics from the Rlc level, which will calculate the **Throughput** in DL and UL for each user separately and display it on the screen.

Let's start with the first point on the list.

### №1 C++
Firstly, I read the [Installation Guide](https://www.nsnam.org/docs/release/3.38/manual/ns-3-manual.pdf), with which I installed the NS-3.
I built and compiled my first test script in the Linux terminal using the commands:

`./ns3 build`

`./ns3 run scratch/myfirst`

The program completed successfully.

![image](https://user-images.githubusercontent.com/129685366/236002989-8a913c5f-d6fb-46dd-90da-093d36853b5c.png)

After I read and executed all of the scripts offered in the [Tutorial](https://www.nsnam.org/docs/release/3.38/tutorial/ns-3-tutorial.pdf), I proceeded to familiarize myself with the [Model Library](https://www.nsnam.org/docs/release/3.38/models/ns-3-model-library.pdf).
The script developed on the basis of the Library Model is located [here](https://github.com/PROKOFEV-DANIIL/Task-for-AME-intern-position/blob/main/ltetest.cc).

This script has output values for DL and UL for RLC and MAC levels, they are also located [here](https://github.com/PROKOFEV-DANIIL/Task-for-AME-intern-position/tree/main/Computing_Throughput), but for convenience I'll give an example here(file "DlRlcStats.txt"):

![image](https://user-images.githubusercontent.com/129685366/236005576-291c3580-9be2-4019-a6ad-612921c5d90d.png)

### №2 Python
To complete the __*second*__ task, it was necessary to read the data from the `".txt"` file. I used the `Pandas` module and the `read_excel()` function. The **throughput** was calculated for both Ue-s on the UL and on the DL. Developed script is located [here](https://github.com/PROKOFEV-DANIIL/Task-for-AME-intern-position/blob/main/Computing_Throughput/LteRlcThroughput.py). The output data of the program are lines with calculated **Throughput** in *Mbps*.

![image](https://user-images.githubusercontent.com/129685366/236017723-6bfb6c59-8474-4e93-83a6-1c6ae7504f73.png)






