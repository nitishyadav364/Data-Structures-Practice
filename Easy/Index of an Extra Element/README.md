<h2><a href="https://www.geeksforgeeks.org/problems/index-of-an-extra-element/1?page=1&company=Amazon,Microsoft,Flipkart,Adobe,Google,Samsung,Paytm,Morgan%20Stanley&difficulty=Easy,Medium,Hard&status=unsolved&sortBy=submissions">Index of an Extra Element</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 20px;">Given two sorted arrays of distinct elements. There is only 1 difference between the arrays. The first array has one element extra added in between. Find the index of the extra element.</span></p>
<p><span style="font-size: 20px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 20px;"><strong>Input:
</strong>n = 7
a[] = {2,4,6,8,9,10,12}
b[] = {2,4,6,8,10,12}
<strong>Output: </strong>4<strong>
Explanation: </strong></span><span style="font-size: 18px;">In the second array, 9 is
missing and it's index in the first array
is 4.</span></pre>
<p><span style="font-size: 20px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 20px;"><strong>Input:
</strong>n = 6
a[] = {3,5,7,9,11,13}
b[] = {3,5,7,11,13}
<strong>Output: </strong>3</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't have to take any input. Just complete the provided function&nbsp;<strong>findExtra</strong>() that takes array a[], b[], and size of a[] and returns the valid index (<strong>0-based indexing</strong>).</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(log n).<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>
<p><span style="font-size: 20px;"><strong>Constraints:</strong><br>2&lt;=n&lt;=10<sup>5</sup><br>1&lt;=a[i],b[i]&lt;=10<sup>6</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Zoho</code>&nbsp;<code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Searching</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;