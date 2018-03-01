<?php
	
	$req1 = $bdd->prepare('INSERT INTO users(login, pass, email, cle) VALUES(:pseudo, :pass, :email, :cle)');
	$req1->execute(array(
    'pseudo' => $pseudo,
    'pass' => $pass,
	'email' => $email,
	'cle' => $cle));
		
	
	?>
