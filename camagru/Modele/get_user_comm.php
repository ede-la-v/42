<?php
	$req = $bdd->prepare('
		SELECT id_membre
		FROM commentaires
		WHERE id_photo = :phot');
	$req->execute(array('phot' => $_POST["img"]));
	$memb = $req->fetch(PDO::FETCH_NUM);
	$id = $memb[0];
	$req = $bdd->prepare('
		SELECT *
		FROM users
		WHERE id = :id');
	$req->execute(array('id' => $id));
	$user = $req->fetch(PDO::FETCH_NUM);

	
	
	?>
