<html>
<body style="background-color:yellow">
<h1><center>Welcome to Ryan Ton's 100% Foolproof Multiplication Test!</center></h1>
<h2><small><center>Let's practice some of your skills! Enter your answer below!</small></h2>

<?php
	$number1 = rand (0, 12);
	$number2 = rand (0, 12);
	echo "$number1 x $number2 = ?";
?>

<form action="lab2page2.php" method="POST">
	<input type="hidden" name="number1" value="<?php echo $number1; ?>" />
	<input type="hidden" name="number2" value="<?php echo $number2; ?>" />
	<input type="number" name="number3" />
	<input type="submit" Value="Calculate" />
</form>

