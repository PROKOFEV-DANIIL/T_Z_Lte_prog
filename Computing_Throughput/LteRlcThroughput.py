import pandas as pd

#Create a function that calculates throughput
def calculating_throughput(RxBytes, t):
    return sum(RxBytes) * 8 / 10**6 / t

if __name__ == "__main__":

    #Reading data from a file, shifting it, because the original data is incorrect for calculation
    DlRlc = pd.read_csv('DlRlcStats.txt', delimiter='\t').shift(periods=1, axis=1)
    UlRlc = pd.read_csv('UlRlcStats.txt', delimiter='\t').shift(periods=1, axis=1)

    #data transfer time calculation
    time = max(max(DlRlc['end']), max(UlRlc['end']))

    #extracting the amount of data transmitted by each Ue
    DlRxBytesUe1, DlRxBytesUe2 = DlRlc[DlRlc.IMSI == 1]['RxBytes'], DlRlc[DlRlc.IMSI == 2]['RxBytes']
    UlRxBytesUe1, UlRxBytesUe2 = UlRlc[DlRlc.IMSI == 1]['RxBytes'], UlRlc[DlRlc.IMSI == 2]['RxBytes']

    #creating output
    print(f'DL Throughput of the first user equipment = {calculating_throughput(DlRxBytesUe1, time)} Mbps')
    print(f'DL Throughput of the second user equipment = {calculating_throughput(DlRxBytesUe2, time)} Mbps')
    print(f'UL Throughput of the first user equipment = {calculating_throughput(UlRxBytesUe1, time)} Mbps')
    print(f'UL Throughput of the second user equipment = {calculating_throughput(UlRxBytesUe2, time)} Mbps')
