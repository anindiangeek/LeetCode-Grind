# Total count
## Easy
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given an array <strong>Arr</strong> of <strong>N</strong> positive integers and a number <strong>K</strong> where <strong>K</strong> is used as a threshold value to divide each element of the array into sum of different numbers. Find the sum of count of the numbers in which array elements are divided.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 4, K = 3
Arr[] = {5, 8, 10, 13}
<strong>Output:</strong> 14
<strong>Explanation:</strong> Each number can be expressed as sum 
of different numbers less than or equal to K as
5 (3 + 2), 8 (3 + 3 + 2), 10 (3 + 3 + 3 + 1), 
13 (3 + 3 + 3 + 3 + 1). So, the sum of count 
of each element is (2+3+4+5)=14.
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5, K = 4
Arr[] = {10, 2, 3, 4, 7}
<strong>Output:</strong> 8
<strong>Explanation:</strong>&nbsp;Each number can be expressed as sum of
different numbers less than or equal to K as
10 (4 + 4 + 2), 2 (2), 3 (3), 4 (4) and 7 (4 + 3).
So, the sum of count of each element is 
(3 + 1 + 1 + 1 + 2) = 8.
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>totalCount()</strong>&nbsp;which takes the&nbsp;array of integers&nbsp;<strong>arr</strong>&nbsp;and&nbsp;<strong>n&nbsp;</strong>as parameters and returns an integer denoting the answer.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>7</sup><br>
0 ≤ Arr<sub>i</sub> ≤ 10<sup>7</sup><br>
1 ≤ K ≤ 10<sup>7</sup></span></p>
 <p></p>
            </div>