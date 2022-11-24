# Check if any valid sequence is divisible by M
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array of N integers, using ‘+’ and ‘-‘ between the elements check if there is a way to form a sequence of numbers that evaluates a number divisible by M.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>â€‹Input :</strong> arr[ ] = {1, 2, 3, 4, 6} and M = 4
<strong>Output :</strong> 1
<strong>Explanation:</strong>
There is a valid sequence i. e., 
(1 - 2 + 3 + 4 + 6), which evaluates to 12 
that is divisible by 4.


</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> arr[ ] = {1, 3, 9} <strong>
Output :</strong>  0 </span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>validSequence()</strong> that takes an array <strong>(arr)</strong>, sizeOfArray <strong>(n)</strong>, an integer <strong>M</strong>&nbsp;and return the <strong>true&nbsp;</strong>if there is a way to form a sequence of numbers which evaluate to a number divisible by M&nbsp;else return <strong>false</strong>. The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N*M).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N*M).</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&nbsp;≤ N &lt;&nbsp;1000<br>
1&nbsp;≤ M &lt;1000</span></p>
</div>