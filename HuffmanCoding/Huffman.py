'''
Created on Jul 20, 2017

@author: John
'''
import sys
import heapq
from collections import defaultdict

def Huffman(frequency):
    heap = [[freq, [char, ""]] for char, freq in frequency.items()]
    heapq.heapify(heap)
    while len(heap) > 1:
        low = heapq.heappop(heap)
        high = heapq.heappop(heap)
        for pairs in low[1:]:
            pairs[1] = "0" + pairs[1]
        for pairs in high[1:]:
            pairs[1] = "1" + pairs[1]
            a=len(pairs[1])
        heapq.heappush(heap, [low[0] + high[0]] + low[1:] + high[1:])
        
    return sorted(heapq.heappop(heap)[1:], key=lambda i: (len(i[-1]), i, a))
        
with open(sys.argv[1], "r") as inputfile:
    text = inputfile.read()
frequency = defaultdict(int)

for char in text:
    frequency[char] += 1
total=sum(frequency.values())
output = Huffman(frequency)

print "Character" + "   "+ "Codeword"+"   " + "Frequency"
avecode=0
for i in output:
    a=len(i[1]) #take average
    b=frequency[i[0]]/round(total)
    avecode+=(a)*(b)
    #sum(a)
    print ""+i[0]+"           " + i[1]+"        " + str(frequency[i[0]]*100/(round(total, 1)))+"%"
print '\n' 
print "Average Codeword Length: " + str(avecode)
print "Original Size (bits): " + str(total*8)
print "Encoding Size (bits): " + str(total*avecode)
print "Compression Ratio: " + str(avecode*a)+"%"