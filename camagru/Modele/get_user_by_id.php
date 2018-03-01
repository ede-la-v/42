<?php
	
	$req = $bdd->prepare('
		SELECT *
		FROM users
		WHERE id = :id');
	$req->execute(array('id' => $_SESSION["id"]));
	$user_comm = $req->fetch(PDO::FETCH_NUM);

	
	
	?>
