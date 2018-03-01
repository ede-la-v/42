<?php
	
		$req = $bdd->prepare('
		UPDATE users 
		SET cle = :cle
		WHERE login = :id');
		$req->execute(array('cle' => $cle, 'id' => $login));

	
	
	?>
