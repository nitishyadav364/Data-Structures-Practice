<h2><a href="https://www.geeksforgeeks.org/problems/tiger-zinda-hai5531/1?page=3&company=Oracle&sortBy=submissions">Find the number of tabs opened</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18.6667px;">You are given an array <strong>arr[]</strong>, where each element is either a tab ID or the string "END". If a tab ID appears, toggle its state (open if it's closed, or close if it's open). If "END" appears, close all open tabs. Your task is to determine the number of tabs that remain open after all operations are completed.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = ["1", "2", "1", "END", "2"]
<strong>Output:</strong> 1
<strong>Explanation: </strong>In the above test case, firstly tab 1st is opened then 2nd is opened then 1st is closed then all are closed then again 2nd is opened.
</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = ["1", "2", "END"]
<strong>Output:</strong> 0<br><strong>Explanation</strong>: 1st and 2nd tab is opened then both closed so zero tabs open at last,<br></span></pre>
<p><span style="font-size: 14pt;"><strong>Expected Time Complexity:</strong> O(n).<br><strong>Expected Auxiliary Space:</strong> O(n).</span></p>
<p><span style="font-size: 14pt;"><strong>Constraints:<br></strong>1 ≤ arr.size() ≤ 10<sup>6<br></sup></span><span style="font-size: 14pt;">1 ≤ arr[i].size() ≤ 6</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Oracle</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Hash</code>&nbsp;<code>Data Structures</code>&nbsp;