class ProductOfNumbers {
public:
vector<int> nums;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        nums.push_back(num);        
    }
    
    int getProduct(int k) {
        int res = 1, i=nums.size()-1;
        while(k>0){
            res*= nums[i--];
            k--;
        }
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */