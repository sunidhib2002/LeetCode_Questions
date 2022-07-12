class SmallestInfiniteSet {
public:
    map<int, int> numbers;
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) {
            numbers[i] = 1;
        }
    }
    
    int popSmallest() { 
        map<int, int> :: iterator it;
        it = numbers.begin();
        pair<int, int> p = *it;
        numbers.erase(p.first);
        return p.first;
    }
    
    void addBack(int num) {
        if (numbers.find(num) == numbers.end()) {
            numbers[num] = 1;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */