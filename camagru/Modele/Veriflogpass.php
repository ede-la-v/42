<?php
	
	$req = $bdd->prepare('SELECT id FROM users WHERE login = :id AND pass = :pass');
	$req->execute(array('id' => $pseudo, 'pass' => $pass));
	$resultat2 = $req->fetch();
	
	?>
