
	
	<?php
	$req = $bdd->prepare('
		SELECT count(id) AS "count"
		FROM likes
		WHERE id_photo = :foto');
	$req->execute(array('foto' => $photo["id"]));
	$like_count = $req->fetch(PDO::FETCH_NUM);

	
	
	?>
