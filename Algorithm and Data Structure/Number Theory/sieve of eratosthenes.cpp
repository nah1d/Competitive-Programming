/*
    Description: This is an efficient algorithm to find all the primes up to a certain limit.First mark all the even numbers except 2 as
                 non prime. Some little observations are necessary to understand the algorithm. First of all, if a number is non prime 
                 then it must have a divisor less than or equal to squre-root(number).So it is enough to run a loop through
                 square-root(number) to check if a number is prime. If a number is not marked yet then it must be a prime. Now we  
                 will mark all the numbers that are divisibe by that prime. Let's think the current prime is i. So we don't need to
                 mark all the numbers below i*i as they have already been marked by other prime.Also we don't need to mark the even 
                 indices as they have already been marked. So we can skip the even indices by writing j+=i*2; Why this is true? Well,
                 this is easy. As primes are odd except 2, if we would write j+=i, then the value would be, even,odd,even odd....like
                 that.   So we can skip the even indices by writing j+=i*2;
               
     
    Test: https://www.spoj.com/problems/TDPRIMES/
    Complexity: O(n log log n)
        
*/

const int limit=1e7+10; //keep an eye on the limit
bitset<limit>is_prime;
vector<int>prime;
void sieve() {
    is_prime.set();
    is_prime[0]=is_prime[1]=0;
    for(int i=4;i<limit;i+=2)
        is_prime[i]=0;
    for(int i=3;i*i<limit;i+=2) {
        if(is_prime[i]) {
            for(int j=i*i;j<limit;j+=i*2)
                is_prime[j]=0;
        }
    }   
    for(int i=2;i<limit;i++)
        if(is_prime[i])
            prime.push_back(i);
}
