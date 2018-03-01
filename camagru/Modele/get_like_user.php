
	
	<?php
	
	$req = $bdd->prepare('
		SELECT id
		FROM likes
		WHERE id_photo = :foto AND id_membre = :user');
	$req->execute(array('foto' => $photo["id"], 'user' => $_SESSION["id"]));
	$like_user = $req->fetch(PDO::FETCH_NUM);

	
	
	?>
