<html>
<body style="background-color:yellow">
<h1><center>Welcome to Ryan Ton's 100% Foolproof Multiplication Test!</center></h1>

<?php
$number1 = $_POST["number1"];
$number2 = $_POST["number2"];
$number3 = $_POST["number3"];
$answer = $number1 * $number2;

if ($number3 == $answer) echo "Correct! Great Job!";
else echo "Whoops, the correct answer was $answer!";
?>

<form method="POST" action="lab2page1.php">
<input type="submit" value="Try again" />
</form>
