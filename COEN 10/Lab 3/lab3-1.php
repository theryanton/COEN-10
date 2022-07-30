<html>
<body style="background-color:tan">

<?php
$array = array(0,0,0,0,0);
$user_input = $_POST["user_input"];

for($i=0; $i<5; $i++) {
	$array[$i] = rand(1,20);
	echo $array[$i]." ";
}

for($j=0; $j<5; $j++){
	if($user_input == $array[$j]) {
		$answer = True; 
		break;
	} else {
		$answer = False;
	}
}
if($answer == True) {
	echo "<p> Nice! You guessed the correct number, $user_input.</p>";
}
else if($answer == False) {
	echo "<p> $user_input is incorrect. Better luck next time! </p>";
}
?>

<form method="POST" action="lab3.html">
<input type="submit" value="Try again" />
</form>
