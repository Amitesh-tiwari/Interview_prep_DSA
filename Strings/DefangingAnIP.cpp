Given a valid (IPv4) IP address, return a defanged version
of that IP address.

A defanged IP address replaces every period "." with 
"[.]".

//code
 string defangIPaddr(string address) {
    int n = address.length();
    string ans;
    for(int i=0;i<n;i++){
        if(address[i] == '.'){
            ans = ans+ "[.]";
        }
        else{
            ans += address[i];
        }
    }
    return ans;
 }