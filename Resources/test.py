import time
import sys
import cv2

print("/Users/xuanli/Documents/fast.mov")
print("\nCurrent opencv package version is " + cv2.__version__ + "\n")

for i in list(range(len(sys.argv))):
    print(sys.argv[i])
    
# Wait for 3 seconds
time.sleep(3)
