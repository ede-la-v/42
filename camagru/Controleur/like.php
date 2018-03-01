<?php
session_start();

if (isset($_SESSION["id"]))
{
	Include_once($_SERVER['DOCUMENT_ROOT'].'/ConnexionBase.php');
	$photo["id"] = $_POST["img"];
	Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/get_like_user.php');
	if ($like_user)
	{
		Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/del_like.php');
		echo 1;
	}
	else
	{
		Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/put_like.php');
		echo 2;
	}
}
else
{
	http_response_code(400);
	echo "Veuillez vous connecter pour realiser cette action";
}

?>
