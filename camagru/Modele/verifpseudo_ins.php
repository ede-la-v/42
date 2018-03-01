<?php
	
	$req = $bdd->prepare('SELECT id FROM users WHERE login = :pseudo');
	$req->execute(array('pseudo' => $pseudo));
	$resultat = $req->fetch();
	
	?>
