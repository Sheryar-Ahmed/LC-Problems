class MedianFinder {
public:
    // Multiset to store the numbers in sorted order
    multiset<int> S;  
    // Iterator to track the middle element
    multiset<int>::iterator mid;  

    MedianFinder() {
    }
    
    void addNum(int num) {
        // Initalize `mid` in case of first element
        if(S.size() == 0) {
            S.insert(num);
            mid = S.begin();
        } 
        else {
            // Insert the number into the multiset
            S.insert(num);  
            
            // Adjust the 'mid' iterator to point to the middle element
            if(S.size() % 2 == 0) {
                if(num < *mid) 
                    mid--;
            } 
            else {
                if(num >= *mid) 
                    mid++;
            }
        }
    }
    
    double findMedian() {
        if(S.size() % 2 == 0) {
            // If the size is even, return the average of the two middle elements
            auto midP = mid; 
            midP++;  // Move to the second middle element
            return (double)(*mid + *midP) / 2;
        } 
        else {
            // If the size is odd, return the middle element
            return *mid;
        }
    }
};