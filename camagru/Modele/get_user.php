<?php
	
	$req = $bdd->prepare('
		SELECT *
		FROM users
		WHERE login = :id');
	$req->execute(array('id' => $login));
	$user = $req->fetch(PDO::FETCH_NUM);

	
	
	?>
