<!-- Ryan Ton
COEN 10L
Tuesday 2:15pm -->

<html>
<body>
	<body style="background-color:violet">
	<h1><center>Let's Play the Lottery!</center></h1>
</body>

<?php
$counter = 0;
$rand_array = array(0,0,0,0,0);
$user_array = array(
	$_POST["number1"],
	$_POST["number2"],
	$_POST["number3"],
	$_POST["number4"],
	$_POST["number5"]);

for($j=0; $j<5; $j++) // This is the loop that randomly generates the winning numbers.
{
	$rand_array[$j] = rand(1,20);
		for($w=$j-1; $w>=0; $w--)
		{
			if ($rand_array[$j] == $rand_array[$w])
				{
					$j--;
					break;
				}
		}
}
for($i=0; $i<5; $i++) // This loop counts all matches between the user inputs and randomly generated numbers.
	for($n=0; $n<5; $n++)
		if ($rand_array[$i] == $user_array[$n])
			$counter++;

echo "You had ".$counter." matches.";
echo "<p>Your guesses were: ";
for($i=0; $i<5; $i++)
	echo $user_array[$i]." ";
echo "</p>";
echo "<p>The winning numbers were: ";
for($j=0; $j<5; $j++)
	echo $rand_array[$j]." ";
echo "</p>"
?>

<form action="lab4.html" method=POST>
<input type="submit" value="Try again" />
</form>
</html>
