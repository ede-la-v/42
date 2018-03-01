
	
	<?php
	
	$req = $bdd->prepare('
		SELECT users.login as "login", commentaires.add_date as "date", comm 
		FROM commentaires 
			INNER JOIN users 
			ON commentaires.id_membre = users.id
		WHERE id_photo = :photo');
	$req->execute(array('photo' => $_POST["img"]));
	$resultat = $req->fetchAll(PDO::FETCH_NUM);

	
	
	?>
