vector<vector<int>> sum2 = twoSum(a, 0, n, x);
    cout << "\n The two sum is : ";
    if(sum2.size() == 0) cout << "-1";
    else{
        for(auto i:sum2)
            cout << "(" << i[0] << ", " << i[1] << ")\n";
    }