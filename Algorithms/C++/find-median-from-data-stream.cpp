class MedianFinder {
private:
    vector<int> max={};
    vector<int> min={};
public:
    void addNum(int num) {
        if (min.size() == 0) {
            min.push_back(num);
            return;
        }
        if (num < min.front()) {
            min.push_back(num);
            push_heap(min.begin(), min.end());
        } else {
            max.push_back(num);
            push_heap(max.begin(), max.end(), greater<int>());
        }
        if (((int)min.size() - (int)max.size()) > 1) {
            pop_heap(min.begin(), min.end());
            max.push_back(min.back());
            min.pop_back();
            push_heap(max.begin(), max.end(), greater<int>());
        } else if (((int)max.size() - (int)min.size()) > 1) {
            pop_heap(max.begin(), max.end(), greater<int>());
            min.push_back(max.back());
            max.pop_back();
            push_heap(min.begin(), min.end());
        }
    }
    
    double findMedian() {
        if (min.size() > max.size()) return (double)min.front();
        else if (min.size() < max.size()) return (double)max.front();
        return (min.front() + max.front()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
